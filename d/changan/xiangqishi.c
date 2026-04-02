// /d/changan/xiangqishi.c
#include <ansi.h>
inherit  ROOM;
string lookjian();
void create ()
{
	set ("short", "適情雅趣屋");
	set ("long", @LONG
房間裏很是雅緻。當中一座大棋盤，棋盤上楚河漢界，將士躍馬橫
炮，《戰國策·秦》雲：“綴甲歷兵，效勝於戰場。”誠如是也。棋盤
邊的小几上擱着一疊薛濤箋(jian)，密密麻麻寫滿不少東西，還有一些
好象是棋經(jing)歌訣(poem)之類的，抄錄得很是整齊，想來頗值一讀
(read)。宋·劉克莊《象弈一首呈葉潛仲》詩云：“小藝無難精，上智
有未解。君看橘中戲，妙不出局外。”何不領略一番？ 
    牆上貼了一張小帖子(tie)。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/chess" : 1,
	]));
	set("item_desc", ([ 
		"poem": HIY"\n	象棋歌訣\n\n"NOR,
		"jing": HIR"\n	棋經論\n\n"NOR,
		"tie":
"

下子        ：move <橫座標> <縱座標> to <橫座標> <縱座標>
重下        ：reset
讀出殘局    ：deploy
記錄殘局    ：csave
擲骰確定先行：toss
回顧        ：review
認輸        ：lose
觀看棋局    ：look或l board或ccb

",
		"jian": (: lookjian :)
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"club3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -5020);
	set("coor/y", 1010);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("do_read", "read");
}
int do_read(string arg)
{
	if (arg == "poem")
		this_player()->start_more(read_file(__DIR__"obj/chess_book"));
	else
	if (arg == "jing")
		this_player()->start_more(read_file(__DIR__"obj/chess_jing"));
	else
                return notify_fail("你要讀什麼？\n");
	return 1;
}
string lookjian()
{
        return
" 
                     以戰爭之象為棋戲

    回溯歷史，春秋時的戰爭主要是車戰，是四馬拉的各種戰車。
    戰車縱聘於平原之上，卻會受到不平坦地形的阻滯，而步兵則無論密草叢
林、丘陵險隘，……這些地帶對戰車是畏途，對步兵則無往而不利。所以到了
戰國時期，步兵部隊就龐大了起來，形成了以步兵部隊為主體，配置以戰車的
軍隊。騎兵的發展，自趙武王“胡服騎射”運動之後，從而使戰術是形成步、
騎、車（即車馬兵）的協同作戰的戰術聯合體，使得戰術組織複雜了許多。
    早期的象棋，在定型前除去無炮外，車、馬、兵齊備，這與古代戰爭中的
兵種是一致的，尤其是五個兵卒，正好符合“五兵為伍”的戰爭中的戰術組合
體。\n"+"
    象棋中的不同兵種協同聯攻的戰術組合體很多，舉不勝舉。諸如：五兵聯
攻，可以形成“五卒擒王”之勢；車馬聯攻，俗稱“車馬冷着”令受攻者防不
勝防；車炮聯攻，能形成“夾車炮”、“滾地雷”以及抽將得子等有迅猛威肋
的殺勢，等等。
    出棋制勝猶如將帥之立奇功，李白計曰：“剪虜若草收奇功！”（《送族
弟館從軍安西》）的機巧戰術，精妙的勝局，使棋迷蕩氣迴腸，如飲甘醴，回
味無窮，妙不可言，是一種超脫世俗的藝術享受！
";
}
