SET(LIST1EXOS
      tuto1_baseDGtal
  )

FOREACH(FILE ${LIST1EXOS})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} DGtalIO DGtal)
ENDFOREACH(FILE)

