
(cl:in-package :asdf)

(defsystem "virtual_device_debugger-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "joyinfoex" :depends-on ("_package_joyinfoex"))
    (:file "_package_joyinfoex" :depends-on ("_package"))
  ))