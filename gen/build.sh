#!/bin/bash

# Usage: ./build.sh problem_dir

PROBLEM_DIR="$1"
HASHES_FILE="$PROBLEM_DIR/hashes"

if [ -z "$PROBLEM_DIR" ]; then
    echo "Usage: $0 <problem_dir>"
    exit 1
fi

# edit this to add more files
declare -A FILES_TO_BIN=(
    ["tc/gen.cc"]="bin/gen"
    ["validator.cc"]="bin/validator"
    ["solution.cc"]="bin/sol"
    ["checker.cc"]="bin/checker"
)

mkdir -p "$PROBLEM_DIR/bin"

for SRC_REL in "${!FILES_TO_BIN[@]}"; do
    SRC="$PROBLEM_DIR/$SRC_REL"
    BIN="$PROBLEM_DIR/${FILES_TO_BIN[$SRC_REL]}"

    if [ ! -f "$SRC" ]; then
        echo "❌ Source file not found: $SRC"
        exit 1
    fi

    # Compute current hash
    CURR_HASH=$(sha1sum "$SRC" | cut -d ' ' -f 1)

    # Read old hash from hashes file
    OLD_HASH=$(grep "^$SRC_REL=" "$HASHES_FILE" 2>/dev/null | cut -d '=' -f 2)

    if [ "$CURR_HASH" != "$OLD_HASH" ]; then
        echo "🔄 Recompiling $SRC_REL ..."
        g++ "$SRC" -o "$BIN"
        if [ $? -ne 0 ]; then
            echo "❌ Failed to compile $SRC_REL"
            exit 1
        fi
        # Update hash in hashes file
        # Remove old entry if exists
        grep -v "^$SRC_REL=" "$HASHES_FILE" 2>/dev/null > "$HASHES_FILE.tmp" || true
        echo "$SRC_REL=$CURR_HASH" >> "$HASHES_FILE.tmp"
        mv "$HASHES_FILE.tmp" "$HASHES_FILE"
        echo "✅ Compiled $SRC_REL"
    else
        echo "✅ $SRC_REL is up to date."
    fi
done
