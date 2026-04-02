inherit ROOM;

string* books = ({
	BOOK_DIR"yljing",
	BOOK_DIR"yljing1",
	BOOK_DIR"yljing2",
	BOOK_DIR"book-bamboo",
	BOOK_DIR"book-silk",
	BOOK_DIR"book-stone",
	BOOK_DIR"book-iron",
	BOOK_DIR"quanpu",
	BOOK_DIR"dujing_1",
});

void create()
{
	set("short", "側廳");
	set("long", @LONG
這裏是側廳，靠牆是一排書架，擺滿了各種拳譜、書籍。牆角有一
張木牀。天地會總舵主陳近南常常在這裏讀書、休息。
LONG );
	set("exits", ([
		"west" : __DIR__"dating",
	]));
        set("sleep_room", 1);   
	set("objects", ([
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
