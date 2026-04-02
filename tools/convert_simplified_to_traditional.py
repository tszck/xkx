from __future__ import annotations

from pathlib import Path

from opencc import OpenCC


ROOT = Path(__file__).resolve().parents[1]
CC = OpenCC("s2t")
TEXT_EXTENSIONS = {
    ".c",
    ".h",
    ".md",
    ".txt",
    ".ini",
    ".js",
    ".html",
    ".xml",
    ".json",
    ".py",
}
EXTRA_TEXT_NAMES = {
    "rules",
    "newbie",
    "intro",
    "shaolin",
    "skill",
    "ms_task",
    "ms_killer",
}
BOM = "\ufeff"
ENCODINGS = ("utf-8", "gbk", "cp936", "big5")


def decode_text(data: bytes) -> tuple[str, str, bool] | tuple[None, None, None]:
    for encoding in ENCODINGS:
        try:
            text = data.decode(encoding)
            had_bom = text.startswith(BOM)
            if text.startswith(BOM):
                text = text.lstrip(BOM)
            return text, encoding, had_bom
        except UnicodeDecodeError:
            continue
    return None, None, None


def is_candidate(path: Path) -> bool:
    if path.suffix.lower() in TEXT_EXTENSIONS:
        return True
    return path.name in EXTRA_TEXT_NAMES


def contains_chinese(text: str) -> bool:
    return any("\u4e00" <= ch <= "\u9fff" for ch in text)


def main() -> None:
    changed_files: list[str] = []
    skipped_files: list[str] = []

    for path in ROOT.rglob("*"):
        if not path.is_file() or not is_candidate(path):
            continue
        if path.name.startswith("."):
            continue

        data = path.read_bytes()
        if b"\x00" in data:
            continue

        text, encoding, had_bom = decode_text(data)
        if text is None or encoding is None:
            continue

        if not contains_chinese(text) and not had_bom:
            continue

        converted = CC.convert(text)
        if converted == text and not had_bom:
            continue

        path.write_text(converted, encoding=encoding, newline="")
        changed_files.append(str(path.relative_to(ROOT)))

    report = ROOT / "tools" / "simplified_to_traditional_report.txt"
    report.write_text("\n".join(changed_files) + ("\n" if changed_files else ""), encoding="utf-8", newline="")
    print(f"changed={len(changed_files)}")
    if skipped_files:
        print(f"skipped={len(skipped_files)}")


if __name__ == "__main__":
    main()