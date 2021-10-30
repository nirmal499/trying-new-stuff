package mod7;

import java.util.*;

public class shopping2 {
    public static void main(String[] args) {
        ShoppingCart myFirstCart = new ShoppingCart(new HashMap<>());
        ShoppingCart mySecondCart = myFirstCart.addItem(new ShoppingItem("Chair", 150));
        ShoppingCart myThirdCart = mySecondCart.addItem(new ShoppingItem("Table", 350));

        ShoppingCart myFourthCart = myThirdCart.removeItem(new ShoppingItem("Table", 350));
        ShoppingCart myFifthCart = myFourthCart.addItem(new ShoppingItem("Table", 350));
        ShoppingCart mySixthCart = myFifthCart.addItem(new ShoppingItem("Table", 350));

        System.out.println("Final Cart is : ");
        for (String key : mySixthCart.mShoppingList.keySet()) {
            System.out.println(key + " is " + mySixthCart.mShoppingList.get(key));
        }

        /* Another method */
        // Iterator<String> it = mySixthCart.mShoppingList.keySet().iterator();
        // while (it.hasNext()) {
        // String key = (String) it.next();
        // System.out.println(key + " is " + mySixthCart.mShoppingList.get(key));
        // }

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

        public final Map<String, Integer> mShoppingList;

        public ShoppingCart(Map<String, Integer> list) {
            mShoppingList = Collections.unmodifiableMap(list);
        }

        public ShoppingCart addItem(ShoppingItem item) {

            Map<String, Integer> newList = new HashMap<>(mShoppingList);
            /* Here value is the no.of that particular item */
            int value = 0;
            if (newList.containsKey(item.name)) {
                value = newList.get(item.name);
            }
            newList.put(item.name, ++value);
            return new ShoppingCart(newList);
        }

        public ShoppingCart removeItem(ShoppingItem item) {
            Map<String, Integer> newList = new HashMap<>(mShoppingList);
            int value = 0;
            if (newList.containsKey(item.name)) {
                value = newList.get(item.name);
            }
            if (value > 0) {
                newList.put(item.name, --value);
            }
            return new ShoppingCart(newList);
        }

        public ShoppingCart addItems(ShoppingItem... items) {
            ShoppingCart newCart = null;
            for (ShoppingItem item : items) {
                newCart = addItem(item);
            }
            return newCart;
        }
    }
}
