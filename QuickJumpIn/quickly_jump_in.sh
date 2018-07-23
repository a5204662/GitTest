#!/bin/bash

LOCAL=`bash -c pwd`
#echo $LOCAL

GetFiles() {
    for file in $(ls $LOCAL*)
    do
        FuzzyMatch $file "test"
        if (( $? == 3 ));
        then
            if [ -f $file ];
            then
                echo $LOCAL"/"$file
                `bash -c vi $LOCAL"/"$file`
            else
                `bash -c cd $LOCAL"/"$file`
            fi
        elif (( $? == 2 ));
        then
            if [ -f $file ];
            then
                echo "prifix file"$file
            else
                echo "prifix dir"$file
            fi
        elif (( $? == 1 ));
        then
            if [ -f $file ];
            then
                echo "fuzzy file : "$file
            else
                echo "fuzzy dir : "$file
            fi
        fi
    done
}

FuzzyMatch() {
    if [[ "$1" = $2 ]];
    then
        echo 3
        return 3;
    elif [[ "$1" =~ $2.* ]];
    then
        echo 2
        return 2;
    elif [[ "$1" =~ .*$2.*  ]];
    then
        return 1;
    else
        return 0;
    fi
}

#FuzzyMatch "11" "11"

`bash -c vi $LOCAL"/"$file`

#GetFiles
