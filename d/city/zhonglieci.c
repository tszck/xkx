// /d/city/zhonglieci.c  忠烈祠
//modified by sega 1/10/99
//修改a_time爲120,並添加newjob的一些信息,以防一些人一直flood
//修改a_time爲300，一些老玩家建議我們延長這個時間。
//修改了2次保鏢間隔爲5分鐘
#include <ansi.h>
#define A_TIME 300 
inherit ROOM;
// 下列地址所在房間必須有outdoors 
string * add_msg = ({
	"/d/city/siqiaoyanyu",		// 四橋煙雨
	"/d/beijing/wangfu1",		// 王府井大街
	"/d/chengdu/wangjianglou1",	// 望江樓
	"/d/suzhou/canlangting",	// 滄浪亭
	"/d/hangzhou/liulangqiao",	// 柳浪橋
	"/d/fuzhou/yongquan",		// 湧泉寺
	"/d/jiaxing/yanyu",		// 煙雨樓
	"/d/xiangyang/juyilang",	// 水上走廊
	"/d/lingzhou/luorilin1",	// 落日林
	"/d/dali/feilihu",		// 妃麗湖畔
	"/d/mobei/hill",		// 小土山
	"/d/village/wexit",		// 西村口
	"/d/jiangling/chenglingji",	// 城陵磯
//	"/d/shaolin/qyping",		// 青雲坪
	"/d/wudang/haohanpo",		// 好漢坡
	"/d/emei/duguangtai",		// 睹光臺
	"/d/qingcheng/huyingting",	// 呼應亭
	"/d/kunlun/pingfeng",		// 石屏風
	"/d/qilian/zibaipo",		// 紫柏坡
	"/d/songshan/tieliang",		// 鐵梁峽
	"/d/taishan/tanhai",		// 探海石
	"/d/huashan/ziqitai",		// 紫氣臺
	"/d/henshan/liuyunping",	// 流雲坪
	"/d/hengshan/tongyuangu",	// 通元谷
	"/d/mingjiao/shanlu3",		// 懸天崖
	"/d/heimuya/xingxingtan",	// 猩猩灘
	"/d/xuedao/wangyougu",		// 忘憂谷
	"/d/gumu/taiyi1",		// 太乙池
	"/d/jueqinggu/duanchangya",	// 斷腸崖
//	"/d/taohua/xiuxishi",		// 桃花軒
//	"/d/baituo/zhuyuan",		// 竹園
//	"/d/shenlong/caoping",		// 草坪
	"/d/xiaoyao/qingcaop",		// 青草坪
	"/d/xiaoyao/pubu",		// 玉壁瀑布
	"/d/lingxiao/sroad4",		// 天風川
//	"/d/lingjiu/daban",		// 綴錦閣
//	"/d/xingxiu/yueerquan",		// 月兒泉
	"/d/xueshan/shenghu",		// 聖湖
	"/d/wudujiao/taohua",		// 桃花峪
	"/d/wuliang/jianhugate",	// 劍湖宮門
	"/d/tianlongsi/yaotai",		// 清都瑤臺
	"/d/yanziwu/tingxiang",		// 聽香水榭
	"/d/guanwai/chuanchang",	// 船廠
	"/d/meizhuang/xiaoyuan",	// 琴音小院
	"/d/shiliang/tingzi",		// 玫瑰小亭
	"/d/tiezhang/mzfeng",		// 拇指峯
});

void create()
{
	set("short", "忠烈祠");
	set("long", @LONG
這裏揚州忠烈祠，是大清鹿鼎公韋小寶奉清聖祖康熙聖諭所築，供
奉的卻是大明盡忠報國、忠君愛民的揚州督師史閣部史可法。堂上牌匾
是康熙御筆“敕建揚州忠烈祠”。匾下史公神像歷久年深，像上的顏色
已經斑駁脫離了。四周的地上積了一些塵土，看來象是已經有些時候沒
有人來過的痕跡。像前擺放着一張紅木高腳供桌，桌上高處，放着一個
神龕(kan)。
LONG    );
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"north" : __DIR__"zizheng",
	]));

	set("count",1);
	set("item_desc", ([
		"kan" :  HIG"
與周遭一比較，你發現這個神龕一塵不染，乾淨得奇怪，好象常有人打開似的。\n
"NOR
	]));
	set("coor/x", -30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open","dakai");
	add_action("do_open","open");

	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}

int do_open(string arg)
{
	object me = this_player();
	object ob,rz;
	string src_add,dest_add,des;
	object room,room2;

	src_add=add_msg[random(sizeof(add_msg))];
	dest_add=add_msg[random(sizeof(add_msg))];
	while (dest_add == src_add)
		dest_add=add_msg[random(sizeof(add_msg))];

	if (!arg || arg != "kan" )
		return 0;

	if (me->query_skill("dodge", 1) < 80)
		return notify_fail("神龕太高了，你的輕功夠不着。\n");

	if ( !wizardp(me) && time() - me->query("baobiaotime") < 300)
		return notify_fail("你的上個任務完成了？辛苦辛苦。歇會吧。\n");

	if (query("count") > 0) {
		if (!present("mi ling",me) ) {
			if (! room = find_object(src_add) )
				room = load_object(src_add);
			rz = new(__DIR__"task2/renzhi");
			rz -> set("leader_name", me->query("id") );
			rz -> set("title",me->query("name")+"所保護的人質");
			rz -> set("dest_add",dest_add);
			rz -> move(room);
			if (! room2 = find_object(dest_add) )
				room2 = load_object(dest_add);
			des = "護送" + to_chinese(room->query("outdoors"))+room->query("short") + "那裏的" + rz->query("name") + "到達" + to_chinese(room2->query("outdoors")) + room2->query("short") ;
			ob = new(__DIR__"task2/miling");
			ob -> set("describe",des);
			ob -> set("src_add",room->query("short") );
			ob -> set("dest_add",room2->query("short") );
			ob -> set("src_des",room->query("outdoors") );
			ob -> set("dest_des",room2->query("outdoors") );
			ob -> move(me);
			me -> set("baobiaotime", time());
			add("count",-1);
message_vision(HIY"$N小心翼翼地打開神龕，發現了一卷紙墊夾在龕門後木縫裏，便順手取出來揣進懷中。\n"NOR,me);
			return 1;
		}
		else
		{
message_vision(YEL"$N試着要打開神龕，一不小心，結果‘轟’的一下供桌給碰倒了。\n"NOR,me);
			return 1;
		}
	}
	else {
message_vision(HIG"$N小心翼翼地打開神龕，發現了裏面啥都沒有。還有誰會來這呢？明天再來吧。\n"NOR,me);
		return 1;
	}
}

void newjob()
{
	object room;
	if (query("count") <= 0) {
		if( room = find_object(__DIR__"zhonglieci") )
		message("vision",YEL"只見一個行跡可疑的灰衣人閃了進來，在神龕那裏搗鼓了幾下，慌裏慌張的走了。\n"NOR,room);
		add("count",1);
	}
	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}

