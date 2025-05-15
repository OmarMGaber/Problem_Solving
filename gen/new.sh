#!/bin/bash

# new.sh: Creates a new problem directory from TEMPLATE with difficulty-based prefix
# Usage: make new p=problem_name d=difficulty (e|em|m|mh|h)

set -e

PROBLEM_NAME="$1"
DIFFICULTY="${d}"
IGNORE="$3"

declare -A DIFFICULTY_MAP=(
  [e]=100
  [em]=150
  [m]=200
  [mh]=250
  [h]=300
)

if [ -z "$PROBLEM_NAME" ] || [ -z "$DIFFICULTY" ]; then
  echo "Usage: make new p=problem_name d=difficulty"
  echo "Example: make new p=foo d=em"
  exit 1
fi

BASE=${DIFFICULTY_MAP[$DIFFICULTY]}

if [ -z "$BASE" ]; then
  echo "❌ Invalid difficulty level: $DIFFICULTY"
  exit 1
fi

NEXT_NUM=$(find . -maxdepth 1 -type d -regex "./${BASE}-[0-9]+-.*" \
  | sed -E "s|./${BASE}-([0-9]+)-.*|\1|" \
  | sort -n | tail -n 1)

if [ -z "$NEXT_NUM" ]; then
  NEXT_NUM=0
else
  NEXT_NUM=$((NEXT_NUM + 1))
fi

FINAL_DIR="${BASE}-${NEXT_NUM}-${PROBLEM_NAME}"
echo "📁 Creating: $FINAL_DIR"

mkdir -p "$FINAL_DIR"
cp -r TEMPLATE/. "$FINAL_DIR/"
echo "✅ Done: $FINAL_DIR"

if [ "$IGNORE" = "t" ] || [ "$IGNORE" = "true" ]; then
  PATTERN="${BASE}-${NEXT_NUM}-*"
  if ! grep -qxF "$PATTERN" .gitignore; then
    echo "$PATTERN" >> .gitignore
    echo "📄 Added \"$PATTERN\" to .gitignore"
  else
    echo "ℹ️ Pattern \"$PATTERN\" already exists in .gitignore"
  fi
fi