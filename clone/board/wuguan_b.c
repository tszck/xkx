// /clone/board/wuguan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("揚州武館留言板", ({ "board" }) );
	set("location", "/d/wuguan/wg_dating");
	set("board_id", "wuguan_b");
	set("long", "這是一個供武館弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

