import re
import struct
import sys
from pathlib import Path


def read_png_dimensions(png_path: Path) -> tuple[int, int]:
    with png_path.open("rb") as f:
        sig = f.read(8)
        if sig != b"\x89PNG\r\n\x1a\n":
            raise ValueError(f"Not a PNG: {png_path}")
        # IHDR must be first
        length_bytes = f.read(4)
        if len(length_bytes) != 4:
            raise ValueError(f"Truncated PNG: {png_path}")
        length = struct.unpack(">I", length_bytes)[0]
        chunk_type = f.read(4)
        if chunk_type != b"IHDR":
            raise ValueError(f"Missing IHDR: {png_path}")
        ihdr = f.read(length)
        if len(ihdr) != length:
            raise ValueError(f"Truncated IHDR: {png_path}")
        width, height = struct.unpack(">II", ihdr[:8])
        return int(width), int(height)


def main() -> int:
    if len(sys.argv) != 3:
        print("usage: gen_level_texture_dims.py <levels/.../texture.inc.c> <output.inc.c>", file=sys.stderr)
        return 2

    texture_inc = Path(sys.argv[1])
    out_path = Path(sys.argv[2])

    text = texture_inc.read_text(encoding="utf-8", errors="replace").splitlines()

    # Match: ALIGNED8 static const Texture <name>[] = {
    # Then an #include "levels/<level>/<file>.<fmt>.inc.c"
    var_decl_re = re.compile(r"^\s*ALIGNED8\s+static\s+const\s+Texture\s+(\w+)\s*\[\]\s*=\s*\{\s*$")
    include_re = re.compile(r"^\s*#include\s+\"(levels/[^\"]+\.inc\.c)\"\s*$")

    entries: list[tuple[str, str, int, int]] = []

    current_var: str | None = None
    for line in text:
        m = var_decl_re.match(line)
        if m:
            current_var = m.group(1)
            continue
        m = include_re.match(line)
        if m and current_var:
            inc_rel = m.group(1)
            png_rel = inc_rel.replace(".inc.c", ".png")
            png_path = Path(png_rel)
            if not png_path.exists():
                current_var = None
                continue
            w, h = read_png_dimensions(png_path)
            entries.append((current_var, png_rel, w, h))
            current_var = None

    out_path.parent.mkdir(parents=True, exist_ok=True)
    with out_path.open("w", encoding="utf-8") as out:
        out.write('#include "texture_dimensions.h"\n')
        for var, _png, w, h in entries:
            out.write(f"REGISTER_TEXTURE_DIMENSIONS({var}, {w}, {h});\n")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
