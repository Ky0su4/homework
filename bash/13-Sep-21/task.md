1. Написать скрипт create.bat, который вызывается с одним аргументом, например `create semest1` создает иерархию папок и файлов:
```sh
semest1
├── algem.sh
├── op.sh
├── Алгебра и геометрия
│   └── readme.txt
├── Дискретная математика
│   └── readme.txt
├── Мат. анализ
│   └── readme.txt
└── Основы программирования
    └── readme.txt

4 directories, 6 files
``` 
и копирует в папку `semestr1` файлы `op.bat` и `algem.bat` из п.2 и п.3 (или, на ваше усмотрение, добавляет в существующие файлы `op.bat` и `algem.bat` информацию о местоположении папки `semestr1` необходимую для их работы). Файл `readme.txt` содержит ФИО преподавателя и строку `«Начало занятий: ****»`, где `****` –это дата запуска скрипта `create.bat`.
2. Написать скрипт `op.bat`, который создает в папке `«основы программирования»` файл с именем `****.log`, где `****` – это текущая дата; пользователь в консоли набирает текст, который помещается в созданный файл (окончание ввода `Ctrl+Z`).
3. Написать скрипт `algem.bat`, который создает в папке `«Алгебра и геометрия»` файл с именем `****.log`, где `****` – это текущая дата; пользователь в консоли набирает текст, который помещается в созданный файл (окончание ввода `Ctrl+Z`).


    Ввиду отсутствия Microsoft Windows на машине, я буду использовать bash скрипты доступные из под Linux
