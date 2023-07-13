import unittest

from landing_zone.gdb_api import *


class TestGdbAPI(unittest.TestCase):
    def test_gdbAPI(self):
        gdbClient = GdbAPI()
        gdbClient.set_target("../testApplication/testApp")
        gdbClient.set_arguments("1")
        gdbClient.set_breakpoint("mock_CVE_2023_0466")
        gdbClient.run_target()
        gdbClient.quit_gdb()


if __name__ == '__main__':
    unittest.main()
