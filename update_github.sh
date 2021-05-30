# clean all the redundant file
ccf

# git add all
cd /Users/$USER/Desktop/codeforce
git add .

# print the status 
git status

# echo commit 
read commit_msg

git commit -m "${commit_msg}"

git push origin master
