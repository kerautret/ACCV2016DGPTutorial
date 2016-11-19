SET(LIST6EXOS
     tuto6_compMT1pt
  )

FOREACH(FILE ${LIST6EXOS})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} DGtalIO DGtal)
ENDFOREACH(FILE)

