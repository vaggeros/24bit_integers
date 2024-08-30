CWD=$PWD
BUILD_DIR=$CWD/build

help(){
    echo Options:
    echo build
    echo run
    echo clean
}

build(){
    cmake -S . -B build
    cmake --build build
}

run(){
    cd $BUILD_DIR && ./main
}

clean() {
    rm -rf $BUILD_DIR
}

"$@"
