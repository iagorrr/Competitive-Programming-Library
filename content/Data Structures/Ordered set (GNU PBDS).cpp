/*8<{=========~ BEGIN ORDERED SET ~===========>8*/
/*8<
     @Title:

          Orderd Set (GNU PBDS)

     @Usage:

          If you need an ordered \textbf{multi}
          set you may add an id to each value.
          Using greater\_equal, or less\_equal
          is considered undefined behavior.


          \begin{compactitem}
            \item  \textbf{order\_of\_key (k)}:
            Number of items strictly
            smaller/greater than k .
            \item  \textbf{find\_by\_order(k)}:
K-th element in a set (counting from zero).
          \end{compactitem}


     @Time:

          Both $O(\log{N})$

     @Warning:

          Is 2 or 3 times slower then a regular
set/map. >8*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag,
         tree_order_statistics_node_update>;

/*8<===========~ END ORDERED SET
 * ~============}>8*/
