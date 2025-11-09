#!/bin/sh
start_time=$(date +%s)

for cmd in "$@"
do
    echo "Виконується команда: $cmd"
    eval "$cmd"
	status=$?
    if [ $status -ne 0 ]; then
        echo "Команда \"$cmd\" завершилася з помилкою (код $status)"
    fi
done

end_time=$(date +%s)

elapsed_time=$((end_time - start_time))

echo "Час, який пройшов після запуску скрипту: $elapsed_time секунд"

