package test;

import java.io.File;

public class FileRenamer {

    public static boolean renameFile(String oldFilePath, String newFileName) {
        try {
            File oldFile = new File(oldFilePath);

            // Kiểm tra xem tệp cũ tồn tại
            if (!oldFile.exists()) {
                System.err.println("Tep cu khong ton tai.");
                return false;
            }

            String parentDirectory = oldFile.getParent();
            File newFile = new File(parentDirectory, newFileName);

            // Thực hiện thay đổi tên tệp
            if (oldFile.renameTo(newFile)) {
                System.out.println("Doi ten thanh cong! " + oldFilePath + " thanh " + newFileName);
                return true;
            } else {
                System.err.println("Khong the doi ten tep.");
                return false;
            }
        } catch (Exception e) {
            System.err.println("Loi khi doi ten tep: " + e.getMessage());
            return false;
        }
    }

    public static void main(String[] args) {

        // Gọi phương thức renameFile để đổi tên tệp
        String oldFilePath = "C:\\Users\\Admin\\Documents\\buivanphu1"; 
        String newFileName = "buivanphu2"; // Tên mới của tệp
        
        renameFile(oldFilePath, newFileName);

    }
}