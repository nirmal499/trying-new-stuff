package mod7;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class shopping1 {
    public static void main(String[] args) {
        ShoppingCart myFirstCart = new ShoppingCart(new ArrayList<ShoppingItem>());
        ShoppingCart mySecondCart = myFirstCart.addItem(new ShoppingItem("Chair", 150));
        ShoppingCart myThirdCart = mySecondCart.addItem(new ShoppingItem("Table", 350));
        /*
         * You'll notice the carts that are created when calling addItem maintain their
         * own unmodifiable list of ShoppingItem, but the immutable ShoppingItem are
         * shared across the lists
         */
        for (int i = 0; i < myThirdCart.mShoppingList.size(); i++) {
            System.out.println(myThirdCart.mShoppingList.get(i).name);
        }

    }

    private static final class ShoppingItem {
        private final String name;
        private final int price;

        public ShoppingItem(String name, int price) {
            this.name = name;
            this.price = price;
        }
    }

    public static final class ShoppingCart {

        public final List<ShoppingItem> mShoppingList;

        public ShoppingCart(List<ShoppingItem> list) {
            mShoppingList = Collections.unmodifiableList(list);
        }

        public ShoppingCart addItem(ShoppingItem item) {
            /*
             * Here we are making a newList by taking the previous mShoppingList So, newList
             * will contain same as what mShoppingList) had. After that we add a new item
             * and then we create unmodifiableList by call the constructor and replace the
             * previous mShoppingList with the newList having the new item
             */
            List<ShoppingItem> newList = new ArrayList<>(mShoppingList);
            newList.add(item);
            return new ShoppingCart(newList);
        }
    }
}
