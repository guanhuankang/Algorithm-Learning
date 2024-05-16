#!/bin/bash
input_folder="notes"
output_folder="notes"

# Loop through each Markdown file and convert it to HTML with a theme
for markdown_file in "$input_folder"/*.md; do
    base_name=$(basename "$markdown_file" .md)
    output_file="$output_folder/$base_name.html"
    pandoc "$markdown_file" -o "$output_file" 
done

echo "Conversion complete! HTML files are saved in $output_folder."
