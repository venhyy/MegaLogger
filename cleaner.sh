#!/bin/bash
echo "Cleaning up any git ignored files..."

# copy and paste the line below to get the same results as running this 
script
git rm --cached `git ls-files -ic --exclude-from=.gitignore`

echo "Finished clean up."

# source: 
https://stackoverflow.com/questions/13541615/how-to-remove-files-that-are-listed-in-the-gitignore-but-still-on-the-repositor/13541721
