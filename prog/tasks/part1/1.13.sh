#!/bin/sh
start_time=$(date +%s)

final_status=0

for cmd in "$@"
do
    echo "Виконується команда: $cmd"
    eval "$cmd"
	final_status=$?
    if [ $final_status -ne 0 ]; then
        echo "Команда \"$cmd\" завершилася з помилкою (код $final_status)"
    fi
done

end_time=$(date +%s)

elapsed_time=$((end_time - start_time))

echo "Час, який пройшов після запуску скрипту: $elapsed_time секунд"

exit $final_status

