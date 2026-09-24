#!/usr/bin/env python3
"""Report which Blind75 / Top150 solution files are present vs missing."""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
SOL = ROOT / "LeetCode" / "solutions"

def links_from(readme: Path):
    text = readme.read_text()
    return sorted(set(re.findall(r"LC\d{4}[a-z0-9\-]*\.md", text)))

def main():
    b75 = links_from(ROOT / "LeetCode" / "Blind75" / "README.md")
    t150 = links_from(ROOT / "LeetCode" / "Top150" / "README.md")
    present = {p.name for p in SOL.glob("LC*.md")} if SOL.exists() else set()

    def report(name, expected):
        missing = [f for f in expected if f not in present]
        print(f"=== {name}: {len(expected)-len(missing)}/{len(expected)} present ===")
        if missing:
            print("Missing:")
            for m in missing:
                print(" ", m)
        return missing

    m1 = report("Blind75", b75)
    m2 = report("Top150", t150)
    print(f"Total solution files on disk: {len(present)}")
    return 1 if (m1 or m2) else 0

if __name__ == "__main__":
    raise SystemExit(main())
