(defun isSafe (chessMat row column)
  (loop for i from 0 to row
     do (if (eql (nth i (nth column chessMat)) 'Q)
	    (print "not safe!"))))

(isSafe '((Q + + +)
	  (+ + + +)
	  (+ + + +)
	  (+ + + +)) 2 0)
