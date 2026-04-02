// /clone/board/shenlong_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("神龍教衆留言板", ({ "board" }) );
	set("location", "/d/shenlong/tingkou");
	set("board_id", "shenlong_b");
	set("long", "這是一個供神龍教下弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
