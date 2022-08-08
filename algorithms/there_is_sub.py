# to search the string p in s, bool.
there_is_sub_aux = {}
def there_is_sub(s, p):
    if(there_is_sub_aux.get(p,-1) == -1):
        if s.find(p) == -1:
            there_is_sub_aux[p] = False
        else:
            there_is_sub_aux[p] = True

    return there_is_sub_aux[p]