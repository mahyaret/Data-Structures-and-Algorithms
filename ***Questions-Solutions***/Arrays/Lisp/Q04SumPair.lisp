(setf marray (make-array 6 :initial-contents '(8 7 2 5 3 1)))
(sort marray #'<)
(print marray)
