#ifndef UTILS_H
#define UTILS_H

template <typename T>
bool is_string_empty(const T& s){
    if(s == T("")){
        return true;
    }
    else{
        return false;
    }
}


#endif // UTILS_H
