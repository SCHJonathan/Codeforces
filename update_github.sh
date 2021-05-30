# reset the git commit
git reset

# clean all the redundant file
ccf

# show the difference
git --no-pager diff

# git add all
cd /Users/$USER/Desktop/codeforce
git add .
git status

read commit_msgs

git commit -m "${commit_msgs}"

git push origin master
