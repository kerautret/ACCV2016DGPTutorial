SET(LIST6EXOS
     tuto6_compMT1pt
      tuto6_compMTAllpt )

FOREACH(FILE ${LIST6EXOS})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} DGtalIO DGtal)
ENDFOREACH(FILE)

