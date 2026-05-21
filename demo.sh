#!/bin/bash

FDF=./build/fdf
TESTS=(test2.txt test3.txt test4.txt)

while true; do
	for map in "${TESTS[@]}"; do
		echo "Affichage de $map..."
		$FDF "$map" &
		PID=$!
		sleep 3
		kill $PID 2>/dev/null
		wait $PID 2>/dev/null
	done
done
