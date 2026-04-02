// /cmds/arch/coor.c 

// Created by Constant Jan 5 2001

inherit F_CLEAN_UP;

mapping map_dirs = ([
	"east"      :    ([ "x" : 10, "y" :  0, "z":  0 ]),
	"west"      :    ([ "x" :-10, "y" :  0, "z":  0 ]),
	"south"     :    ([ "x" :  0, "y" :-10, "z":  0 ]),
	"north"     :    ([ "x" :  0, "y" : 10, "z":  0 ]),
	"up"        :    ([ "x" :  0, "y" :  0, "z": 10 ]),
	"down"      :    ([ "x" :  0, "y" :  0, "z":-10 ]),
	"eastup"    :    ([ "x" : 10, "y" :  0, "z": 10 ]),
	"westup"    :    ([ "x" :-10, "y" :  0, "z": 10 ]),
	"southup"   :    ([ "x" :  0, "y" :-10, "z": 10 ]),
	"northup"   :    ([ "x" :  0, "y" : 10, "z": 10 ]),
	"eastdown"  :    ([ "x" : 10, "y" :  0, "z":-10 ]),
	"westdown"  :    ([ "x" :-10, "y" :  0, "z":-10 ]),
	"southdown" :    ([ "x" :  0, "y" :-10, "z":-10 ]),
	"northdown" :    ([ "x" :  0, "y" : 10, "z":-10 ]),
	"southeast" :    ([ "x" : 10, "y" :-10, "z":  0 ]),
	"northeast" :    ([ "x" : 10, "y" : 10, "z":  0 ]),
	"southwest" :    ([ "x" :-10, "y" :-10, "z":  0 ]),
	"northwest" :    ([ "x" :-10, "y" : 10, "z":  0 ])
]);

int file_count;

int non_recur_do(object room, int x, int y, int z, string prefix);
void clear_old_coor(object room);

int main(object me, string arg)
{
        int x, y, z, i;
        int single = 0, all = 0;
        object env = environment(me);
        string prefix, *file_name;

        if (!me->query("env/yesiknow"))
                return notify_fail("危險指令，慎用！慎用！\n");

	set_eval_limit(2100000000);
	reset_eval_cost();

	if (!arg) {
		if (env->query("border")) {
                	write("房間 " + base_name(env) + " 已非邊界。\n");
                	env->delete("border");
                	return 1;
                } else 
			return notify_fail("這裏本來就不是邊界。\n");
	}

	if (member_array(arg, keys(map_dirs)) != -1) {
        	if (env->query("border/" + arg)) {
                	write("房間 " + base_name(env) + " 已非邊界。\n");
                	env->delete("border");
                	return 1;
                } else {
	               	env->set("border/" + arg, 1);
        	       	write("房間 " + base_name(env) + " 的" + arg + "方向已設爲邊界。\n");
               		return 1;
        	}
        }

	if (sscanf(arg, "-s %s", arg))
		single = 1;
		
	if (sscanf(arg, "-a %s", arg))
		all = 1;

        if (sscanf(arg, "%d,%d,%d", x, y, z) != 3)
               	return notify_fail("用法不對，請參考幫助。\n");

        seteuid(getuid());

	file_count = 0;
	file_name = explode(base_name(env), "/");
	prefix = "";
	
	if (!all) {
       		for (i = 0; i < sizeof(file_name)-1; i ++)
        		prefix += file_name[i] + "/";
        }

        if (env->query("coor") || single) {
        	if (env->query("coor"))
        		clear_old_coor(env);
                if (env->query("coor") != 0)
	                write("房間 " + base_name(env) + " 座標重新設定成功。\n");
	        else
	        	write("房間 " + base_name(env) + " 座標設定成功。\n");
                env->set("coor/x", x);
                env->set("coor/y", y);
                env->set("coor/z", z);
                file_count ++;
        } else
                non_recur_do(env, x, y, z, prefix);

	write("共定位 " + sprintf("%d", file_count) + " 個房間。\n");
        return 1;
}

int non_recur_do(object room, int x, int y, int z, string prefix)
{
	mapping roomlist = ([]);
        mapping exits;
        string *directions;
        string dir;
        object curr_room, next_room;
        int i, border = 0;

        room->set("coor/x", x);
       	room->set("coor/y", y);
       	room->set("coor/z", z);
       	file_count ++;
        write("房間 " + base_name(room) + " 座標設定成功。\n");
        roomlist += ([base_name(room) : room]);

	while (sizeof(roomlist)) {

        	reset_eval_cost();

		curr_room = values(roomlist)[0];
		map_delete(roomlist, keys(roomlist)[0]);

        	if (curr_room->query("border"))
        		border = 1;

	        exits = curr_room->query("exits");
	        if (!mapp(exits) || !sizeof(exits))
        	        return 1;

	        directions = keys(exits);

	        for (i = 0; i < sizeof(directions); i ++) {

	        	reset_eval_cost();
	        	
        	        x = (int)curr_room->query("coor/x");
                	y = (int)curr_room->query("coor/y");
                	z = (int)curr_room->query("coor/z");

                	dir = directions[i];
                	if(!objectp(next_room=find_object(exits[dir])))
                        	next_room=load_object(exits[dir]);

			if (map_dirs[dir]) {
				x += map_dirs[dir]["x"];
				y += map_dirs[dir]["y"];
				z += map_dirs[dir]["z"];
			}
			
			reset_eval_cost();
			if (!next_room->query("coor") 
			    && !roomlist[base_name(next_room)]
			    && (strsrch(base_name(next_room), prefix) != -1
			    	|| prefix == "" )) {
				if (!border) {
				        next_room->set("coor/x", x);
       					next_room->set("coor/y", y);
       					next_room->set("coor/z", z);
       					file_count ++;
        				write("房間 " + base_name(next_room) + " 座標設定成功。\n");
       				        roomlist += ([base_name(next_room) : next_room]);
       				} else if (!curr_room->query("border/" + dir)){
				        next_room->set("coor/x", x);
       					next_room->set("coor/y", y);
       					next_room->set("coor/z", z);
       					file_count ++;
        				write("房間 " + base_name(next_room) + " 座標設定成功。\n");
       				        roomlist += ([base_name(next_room) : next_room]);
       				}
       			}
		}
        }

        return 1;
}

void clear_old_coor(object room)
{
	int x, y, z;
	string file;
	
	x = room->query("coor/x");
	y = room->query("coor/y");
	z = room->query("coor/z");
	
	file = read_file(base_name(room) + ".c");
	file = replace_string(file, sprintf("set(\"coor/x\", %d);\n\t", x), "");
	file = replace_string(file, sprintf("set(\"coor/y\", %d);\n\t", y), "");
	file = replace_string(file, sprintf("set(\"coor/z\", %d);\n\t", z), "");
	write_file(base_name(room) + ".c", file, 1);

}

int help(object me)
{
write(@HELP
指令格式 : coor <參數> x,y,z

用法：
        coor		清除當前房間所有方向的邊界屬性。
        coor <方向>	若該當前房間的該方向已爲邊界，則清除之，否則
        		設置該方向爲邊界。
        coor x,y,z	若當前房間已定位，則重新單獨設定該當前房間的
        		座標；否則連鎖處理，直到同一目錄下所有房間都
        		被處理過爲止。
        coor -a x,y,z	同上，但無同一目錄限制。
	coor -s x,y,z	無論當前房間是否已定位，重新並單獨處理該房間。
	
HELP
);
    return 1;
}
