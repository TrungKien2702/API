import ctypes
from ctypes import wintypes
import datetime

# Load thư viện kernel32.dll
kernel32 = ctypes.WinDLL('kernel32')

# Định nghĩa các kiểu dữ liệu và hàm cần sử dụng
class SYSTEMTIME(ctypes.Structure):
    _fields_ = [
       ('wYear', wintypes.WORD),
        ('wMonth', wintypes.WORD),
        ('wDayOfWeek', wintypes.WORD),
        ('wDay', wintypes.WORD),
    ]

GetSystemTime = kernel32.GetSystemTime
GetSystemTime.argtypes = [ctypes.POINTER(SYSTEMTIME)]

# Lấy thời gian hệ thống
system_time = SYSTEMTIME()
GetSystemTime(ctypes.byref(system_time))

# Trích xuất thông tin ngày tháng
year = system_time.wYear
month = system_time.wMonth
day = system_time.wDay

# Tạo đối tượng datetime từ thông tin ngày tháng
current_date = datetime.datetime(year, month, day)

# Định dạng ngày tháng theo định dạng "ngày/tháng/năm"
formatted_date = current_date.strftime("%d/%m/%Y")

# In ra ngày tháng hiện tại
print("Ngày hôm nay là:", formatted_date)