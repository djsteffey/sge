namespace sge{
    namespace util{
        unsigned long generateUniqueId(){
            unsigned long next_id = 1;
            return next_id++;
        }
    }
}