import unittest

from landing_zone.conf import *


class TestConf(unittest.TestCase):
    def test_conf(self):
        test_file = "../conf.yaml"
        exe, args, funcs = get_target_conf(test_file)
        self.assertEqual("testApplication/testApp", exe)
        self.assertIn("1", args)
        self.assertIn("2", args)
        self.assertIn("3", args)
        self.assertIn("mock_CVE_2023_0466", funcs)
        self.assertIn("mock_CVE_2023_0215", funcs)
        self.assertIn("mock_CVE_2022_4450", funcs)


if __name__ == '__main__':
    unittest.main()
