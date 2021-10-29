package mod2;

import java.sql.*;

public class jdbcQuery {
    public static void main(String[] args) {

        Connection conn = null;
        Statement getStatement = null;
        PreparedStatement updateStatement = null;
        ResultSet results1 = null;
        ResultSet results2 = null;

        try {

            String dbinfo = "user=javauser&password=euySNxaEE$f9~2RK";
            String url = "jdbc:mysql://localhost/jdbcdb?" + dbinfo;
            conn = DriverManager.getConnection(url);

            String sql1 = "select * from customer";
            String sql3 = "select * from email";

            getStatement = conn.createStatement();

            results1 = getStatement.executeQuery(sql1);
            System.out.println("Customers : ");
            /*
             * Java does not have a datatype for unsigned integers. You can define a long
             * instead of an int if you need to store large values
             */
            while (results1.next()) {
                int id = results1.getInt("customer_id");
                // Long id = results1.getLong("customer_id");
                String username = results1.getString("username");
                String firstName = results1.getString("first_name");
                String lastName = results1.getString("last_name");
                System.out.println(id + " " + username + " " + firstName + " " + lastName);
            }

            results2 = getStatement.executeQuery(sql3);
            System.out.println("Emails : ");
            while (results2.next()) {
                int id = results2.getInt("customer_id");
                // Long id = results2.getLong("customer_id");
                String email_address = results2.getString("email_address");
                String email_type = results2.getString("email_type");
                System.out.println(id + " " + email_address + " " + email_type);
            }

            /*
             * -----------------------------------------------------------------------------
             */

            /*
             * By default, a JDBC connection starts in auto-commit mode. This means that
             * each JDBC connection gets committed one at a time. If you want to group a few
             * statements together in a transaction, you first need to turn off auto-commit
             * mode
             */
            conn.setAutoCommit(false);

            String sql2 = "UPDATE email " + "SET EMAIL_ADDRESS = ? " + "WHERE customer_id = ? " + "AND email_type = ? ";
            updateStatement = conn.prepareStatement(sql2);

            updateStatement.setString(1, "bob.marley@another_hugecompany.com");
            /* statement.setLong(2, 1L); */
            updateStatement.setInt(2, 1);
            updateStatement.setString(3, "WORK");
            int rowsChanged = updateStatement.executeUpdate();

            conn.commit();
            System.out.println("Row changed: " + rowsChanged);

            /*
             * -----------------------------------------------------------------------------
             */
            results2.close();

            results2 = getStatement.executeQuery(sql3);
            System.out.println("Emails : ");
            while (results2.next()) {
                int id = results2.getInt("customer_id");
                // Long id = results2.getLong("customer_id");
                String email_address = results2.getString("email_address");
                String email_type = results2.getString("email_type");
                System.out.println(id + " " + email_address + " " + email_type);
            }

        } catch (Exception e) {
            e.printStackTrace();

            try {
                if (conn != null) {
                    conn.rollback();
                }
            } catch (SQLException nested) {
                nested.printStackTrace();
            }
        } finally {
            try {
                conn.setAutoCommit(true);

                if (updateStatement != null) {
                    updateStatement.close();
                }
                if (results1 != null) {
                    results1.close();
                }
                if (results2 != null) {
                    results2.close();
                }
                if (getStatement != null) {
                    getStatement.close();
                }

                conn.close();
            } catch (SQLException nested) {
                nested.printStackTrace();
            }
        }
    }
}
