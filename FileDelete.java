
package test;

import java.io.File;
public class FileDelete {

public class FileDeletionAPI {
    public static boolean deleteFile(String filePath) {
        try {
            File file = new File(filePath);
            if (file.exists()) {
                return file.delete();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    public static void main(String[] args) {
        String filePath = "C:\\Users\\Admin\\Documents\\buivanphu";
        boolean deleted = deleteFile(filePath);

        if (deleted) {
            System.out.println("Tệp đã được xóa.");
        } else {
            System.out.println("Không thể xóa tệp.");
        }
    }
}
}
