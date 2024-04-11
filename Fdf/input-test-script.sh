#!/bin/bash

dir="./test_maps"

for file in "$dir"/*
do
	echo "this is what cat does:"
	cat "$file"
	echo "this is what fdf does:"
	./fdf "$file"
done
