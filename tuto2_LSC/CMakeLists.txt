SET(LIST2EXOS
      exercise2LSC
  )

FOREACH(FILE ${LIST2EXOS})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} DGtalIO DGtal)
ENDFOREACH(FILE)

