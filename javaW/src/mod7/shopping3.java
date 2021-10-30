package mod7;

import java.util.*;

public class shopping3 {
    public static void main(String[] args) {
        List<ShoppingItem> books = new ArrayList<>();
        books.add(new ShoppingItem("Java Fundamentals", 100));
        books.add(new ShoppingItem("Java 11 Quick Start", 200));

        /*
         * Instead of using Collections.unmodifiableList() to create an unmodifiable
         * view of the list, we create an immutable copy of this list with
         * List.copyOf(). The difference in our example is invisible for the user –
         * however, at the bottom, they're based on different implementations; the
         * UnmodifiableCollection and ImmutableCollections classes, respectively.
         */
        List<ShoppingItem> immutableCopy = List.copyOf(books);
        List<ShoppingItem> unmodifiableCopy = Collections.unmodifiableList(books);

        System.out.println(immutableCopy);
        System.out.println(unmodifiableCopy);

        books.remove(0);
        System.out.println(immutableCopy);
        System.out.println(unmodifiableCopy);
        /*
         * immutableCopy is kind of like separate copy. But unmodifiableCopy is
         * basically pointing to same list
         */
        /*
         * In the unmodifiable version, the list can still be changed, and the
         * unmodifiable view will pick up on that change, whereas the immutable version
         * will ignore that change because it contains a new list of items
         */
    }

    private static final class ShoppingItem {
        private final String name;
        private final int price;

        public ShoppingItem(String name, int price) {
            this.name = name;
            this.price = price;
        }

        /* This function is used when someone try to print an object of this class */
        @Override
        public String toString() {
            return name + ", " + price;
        }
    }

    public static final class ShoppingCart {

        public final List<ShoppingItem> mShoppingList;

        public ShoppingCart(List<ShoppingItem> list) {
            mShoppingList = Collections.unmodifiableList(list);
        }

        public ShoppingCart addItem(ShoppingItem item) {
            List<ShoppingItem> newList = new ArrayList<>(mShoppingList);
            newList.add(item);
            return new ShoppingCart(newList);
        }

        /* This function is used when someone try to print an object of this class */
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder("Cart: ");
            for (int i = 0; i < mShoppingList.size(); i++) {
                sb.append(mShoppingList.get(i)).append(", ");
            }
            return sb.toString();
        }
    }
}
