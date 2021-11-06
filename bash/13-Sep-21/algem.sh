while true; do
    read var
    echo "$var" >> "Алгебра и геометрия/$(date +"%a %d-%b-%g").log"
done