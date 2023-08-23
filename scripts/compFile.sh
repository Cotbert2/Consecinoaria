echo $1;
g++ -o "./"$1 $1".cpp"
echo "Creating file ./"$1 
echo  "exec ./"$1
./$1