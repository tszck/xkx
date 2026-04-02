// Room: /d/lingxiao/book.c
// Last Modified by winder on Jul. 15 2001

inherit ROOM; 
string* books = ({
	BOOK_DIR+"book-bamboo",
	BOOK_DIR+"book-silk",
	BOOK_DIR+"book-stone",
	BOOK_DIR+"book-iron",
});
void create()
{
	set("short","書房");
	set("long",@LONG
這裏是白自在的書房，一室之內，放滿了各類書籍。白自在雖然狂
妄自大，但説到學問，卻當真也是飽讀詩書，學富五車。這裏的書架，
大大小小，總有十幾個吧。白自在的書童正在這為他整理。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east"   : __DIR__"weideju",   
		"south"  : __DIR__"bridge",
	]));
	set("objects", ([  
		__DIR__"npc/su" : 1,  
		BOOK_DIR+"feixue-book" : 1,  
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup(); 
	replace_program(ROOM);
}

