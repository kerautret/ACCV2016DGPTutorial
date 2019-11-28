SET(LIST5EXOS
     tuto5_compATSTC
  )

FOREACH(FILE ${LIST5EXOS})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} ${DGTAL_LIBRARIES} ${TutoDependencies})
ENDFOREACH(FILE)

