// /clone/board/bug_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("bug處理版", ({ "board" }) );
	set("location", "/d/wizard/bug_room");
	set("board_id", "bug_b");
	set("long", "這是一個專供巫師處理玩家舉報bug的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}