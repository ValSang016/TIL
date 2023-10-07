
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.ResultSetMetaData;
import java.sql.DatabaseMetaData;

public class Main {
    public static void main(String[] args) {
        Connection con = null;
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url="jdbc:mysql://127.0.0.1/university";
            String user="root", passwd="";
            con=DriverManager.getConnection(url,user,passwd);
            System.out.println(con);
        }catch(ClassNotFoundException e){
            e.printStackTrace();
        }catch(SQLException e){  e.printStackTrace();
        }

        //Update하기
        Statement stmt = null;
//        try {
//            stmt = con.createStatement(); String update = "update instructor set salary = salary * 1.1 where dept_name = 'Finance'";
//            int count = stmt.executeUpdate(update);
//            System.out.println(count);
//        } catch (SQLException e1) {
//            e1.printStackTrace();
//        }
        //Select하여 table 표시하기
        ResultSet rs = null;
//        try {
//            stmt = con.createStatement();
//            String sql = "select name, course_id from instructor natural join teaches";
//            rs = stmt.executeQuery(sql);
//            while (rs.next()) {
//                String name = rs.getString(1);
//                if (rs.wasNull()) name = "null";
//                    String course_id = rs.getString(2);
//                if (rs.wasNull())
//                    course_id = "null";
//                System.out.println(name + "\t" + course_id);
//            }
//        } catch (SQLException e1) {
//            e1.printStackTrace();
//        }

        PreparedStatement pstmt = null;
//        try {
//            String psql = "insert into instructor value (?, ?, ?, ?)";
//            pstmt = con.prepareStatement(psql);
//            String id = "12345", name = "Neumann", dept_name = "Biology";
//            int salary = 98000;
//            pstmt.setString(1, id);
//            pstmt.setString(2, name);
//            pstmt.setString(3, dept_name);
//            pstmt.setInt(4, salary);
//            int count = pstmt.executeUpdate(); System.out.println(count);
//        } catch (SQLException e1) {
//            e1.printStackTrace();
//        }


//        try {
//            stmt = con.createStatement();
//            String sql = "select * from instructor natural join teaches";
//            rs = stmt.executeQuery(sql);
//
//            ResultSetMetaData rsmd = rs.getMetaData();
//
//            for (int i = 1; i <= rsmd.getColumnCount(); i++) {
//                System.out.print(rsmd.getColumnName(i) + " (");
//                System.out.print(rsmd.getColumnTypeName(i) + ")\t");
//            } System.out.println();
//        }catch (SQLException e){
//            e.printStackTrace();
//        }

        DatabaseMetaData dbmd = null;
        ResultSet mdrs = null;
        try {
            dbmd = con.getMetaData();
            mdrs = dbmd.getColumns("university", null, "student", null);
            String[] column = { "COLUMN_NAME", "TYPE_NAME" };
            System.out.println(column[0] + "\t" + column[1]);
            while (mdrs.next()) {
                String column_name = mdrs.getString(column[0]);
                String type_name = mdrs.getString(column[1]); System.out.println(column_name + "\t" + type_name);
            } } catch (SQLException e1) {
            e1.printStackTrace();
        }




        try{
            if(con!=null && !con.isClosed())
                con.close();
         }catch(SQLException e){
            e.printStackTrace();
         }


    }

}