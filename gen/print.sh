#!/bin/bash
# Usage: ./print.sh filename

FILE="$1"
MAX_CHARS=300

if [ ! -f "$FILE" ]; then
    echo "File not found: $FILE"
    exit 1
fi

FILE_SIZE=$(wc -c < "$FILE")

if [ "$FILE_SIZE" -le "$MAX_CHARS" ]; then
    cat "$FILE"
else
    head -c "$MAX_CHARS" "$FILE"
    echo
    echo "... (truncated)"
fi
