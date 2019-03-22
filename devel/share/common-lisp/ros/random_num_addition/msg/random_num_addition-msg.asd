
(cl:in-package :asdf)

(defsystem "random_num_addition-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "random" :depends-on ("_package_random"))
    (:file "_package_random" :depends-on ("_package"))
    (:file "summ" :depends-on ("_package_summ"))
    (:file "_package_summ" :depends-on ("_package"))
  ))