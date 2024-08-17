import unittest

import papt

class TestBug(unittest.TestCase):
    """
    ?
    """
    def setUp(self):
        """
        Prepare the tests
        """
        pass

    def test_bug2(self):
        """
        """
        a = 1
        p = False

        for p in (False, True):
            print('\n\tPython: a = {}\tp = {}'.format(a, p))

            self.assertTrue(papt.bug.bug2(a, p))

    def test_bug3(self):
        """
        """
        a = 1
        b = -2
        p = False

        for p in (False, True):
            print('\n\tPython: a = {}\tb = {}\tp = {}'.format(a, b, p))

            self.assertTrue(papt.bug.bug3(a, b, p))

    def test_bug4(self):
        """
        """
        a = 1
        b = -2
        c = 3
        p = False

        for p in (False, True):
            print('\n\tPython: a = {}\tb = {}\tc = {}\tp = {}'.format(a, b, c, p))

            self.assertTrue(papt.bug.bug4(a, b, c, p))

if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestBug)
    unittest.TextTestRunner(verbosity=2).run(suite)
