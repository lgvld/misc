#tl=$(git rev-parse --show-toplevel)
#path=${tl}/.gitignore

#echo $path

#r=$(git check-ignore ${tl})

#echo $r

git check-ignore $(git rev-parse --show-toplevel)/* | xargs -n 1 basename
