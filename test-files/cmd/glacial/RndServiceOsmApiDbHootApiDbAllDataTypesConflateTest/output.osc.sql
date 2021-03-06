INSERT INTO changesets (id, user_id, created_at, closed_at) VALUES (3, 1, (now() at time zone 'utc'), (now() at time zone 'utc'));
INSERT INTO changeset_tags (changeset_id, k, v) VALUES (3, 'written_by', 'Hootenanny');
/* modify node 38*/
INSERT INTO nodes (node_id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (38, 389109693, -1047145693, 3, true, (now() at time zone 'utc'), 1329041814, 2);
UPDATE current_nodes SET latitude=389109693, longitude=-1047145693, changeset_id=3, visible=true, "timestamp"=(now() at time zone 'utc'), tile=1329041814, version=2 WHERE id=38;
DELETE FROM current_node_tags WHERE node_id = 38;
DELETE FROM node_tags WHERE node_id = 38;
INSERT INTO current_node_tags (node_id, k, v) VALUES (38, 'accuracy', '100');
INSERT INTO node_tags (node_id, k, v, version) VALUES (38, 'accuracy', '100', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (38, 'note', '1-a;2-a');
INSERT INTO node_tags (node_id, k, v, version) VALUES (38, 'note', '1-a;2-a', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (38, 'poi', 'yes');
INSERT INTO node_tags (node_id, k, v, version) VALUES (38, 'poi', 'yes', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (38, 'hoot:id', '38');
INSERT INTO node_tags (node_id, k, v, version) VALUES (38, 'hoot:id', '38', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (38, 'hoot:status', '3');
INSERT INTO node_tags (node_id, k, v, version) VALUES (38, 'hoot:status', '3', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (38, 'name', 'Starbucks');
INSERT INTO node_tags (node_id, k, v, version) VALUES (38, 'name', 'Starbucks', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (38, 'amenity', 'cafe');
INSERT INTO node_tags (node_id, k, v, version) VALUES (38, 'amenity', 'cafe', 2);
/* modify node 39*/
INSERT INTO nodes (node_id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (39, 388467218, -1048852147, 3, true, (now() at time zone 'utc'), 1329016285, 2);
UPDATE current_nodes SET latitude=388467218, longitude=-1048852147, changeset_id=3, visible=true, "timestamp"=(now() at time zone 'utc'), tile=1329016285, version=2 WHERE id=39;
DELETE FROM current_node_tags WHERE node_id = 39;
DELETE FROM node_tags WHERE node_id = 39;
INSERT INTO current_node_tags (node_id, k, v) VALUES (39, 'accuracy', '1000');
INSERT INTO node_tags (node_id, k, v, version) VALUES (39, 'accuracy', '1000', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (39, 'poi', 'yes');
INSERT INTO node_tags (node_id, k, v, version) VALUES (39, 'poi', 'yes', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (39, 'hoot:id', '39');
INSERT INTO node_tags (node_id, k, v, version) VALUES (39, 'hoot:id', '39', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (39, 'leisure', 'park');
INSERT INTO node_tags (node_id, k, v, version) VALUES (39, 'leisure', 'park', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (39, 'hoot:status', '3');
INSERT INTO node_tags (node_id, k, v, version) VALUES (39, 'hoot:status', '3', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (39, 'alt_name', 'Red Rock Canyons');
INSERT INTO node_tags (node_id, k, v, version) VALUES (39, 'alt_name', 'Red Rock Canyons', 2);
INSERT INTO current_node_tags (node_id, k, v) VALUES (39, 'name', 'Red Rock Canyon');
INSERT INTO node_tags (node_id, k, v, version) VALUES (39, 'name', 'Red Rock Canyon', 2);
/* create node 185*/
INSERT INTO nodes (node_id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (185, 388887009, -1047187702, 3, true, (now() at time zone 'utc'), 1329041620, 1);
INSERT INTO current_nodes (id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (185, 388887009, -1047187702, 3, true, (now() at time zone 'utc'), 1329041620, 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (185, 'accuracy', '1000');
INSERT INTO node_tags (node_id, k, v, version) VALUES (185, 'accuracy', '1000', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (185, 'note', '2-c');
INSERT INTO node_tags (node_id, k, v, version) VALUES (185, 'note', '2-c', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (185, 'poi', 'yes');
INSERT INTO node_tags (node_id, k, v, version) VALUES (185, 'poi', 'yes', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (185, 'hoot:id', '185');
INSERT INTO node_tags (node_id, k, v, version) VALUES (185, 'hoot:id', '185', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (185, 'hoot:status', '2');
INSERT INTO node_tags (node_id, k, v, version) VALUES (185, 'hoot:status', '2', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (185, 'name', 'Starbucks');
INSERT INTO node_tags (node_id, k, v, version) VALUES (185, 'name', 'Starbucks', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (185, 'amenity', 'cafe');
INSERT INTO node_tags (node_id, k, v, version) VALUES (185, 'amenity', 'cafe', 1);
/* create node 188*/
INSERT INTO nodes (node_id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (188, 388942750, -1047187095, 3, true, (now() at time zone 'utc'), 1329041792, 1);
INSERT INTO current_nodes (id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (188, 388942750, -1047187095, 3, true, (now() at time zone 'utc'), 1329041792, 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (188, 'accuracy', '1000');
INSERT INTO node_tags (node_id, k, v, version) VALUES (188, 'accuracy', '1000', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (188, 'note', '2-b');
INSERT INTO node_tags (node_id, k, v, version) VALUES (188, 'note', '2-b', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (188, 'poi', 'yes');
INSERT INTO node_tags (node_id, k, v, version) VALUES (188, 'poi', 'yes', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (188, 'hoot:id', '188');
INSERT INTO node_tags (node_id, k, v, version) VALUES (188, 'hoot:id', '188', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (188, 'hoot:status', '2');
INSERT INTO node_tags (node_id, k, v, version) VALUES (188, 'hoot:status', '2', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (188, 'name', 'Starbucks');
INSERT INTO node_tags (node_id, k, v, version) VALUES (188, 'name', 'Starbucks', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (188, 'amenity', 'cafe');
INSERT INTO node_tags (node_id, k, v, version) VALUES (188, 'amenity', 'cafe', 1);
/* create node 189*/
INSERT INTO nodes (node_id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (189, 388747831, -1047208596, 3, true, (now() at time zone 'utc'), 1329041601, 1);
INSERT INTO current_nodes (id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (189, 388747831, -1047208596, 3, true, (now() at time zone 'utc'), 1329041601, 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (189, 'accuracy', '150');
INSERT INTO node_tags (node_id, k, v, version) VALUES (189, 'accuracy', '150', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (189, 'note', '2-e');
INSERT INTO node_tags (node_id, k, v, version) VALUES (189, 'note', '2-e', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (189, 'poi', 'yes');
INSERT INTO node_tags (node_id, k, v, version) VALUES (189, 'poi', 'yes', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (189, 'hoot:id', '189');
INSERT INTO node_tags (node_id, k, v, version) VALUES (189, 'hoot:id', '189', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (189, 'hoot:status', '2');
INSERT INTO node_tags (node_id, k, v, version) VALUES (189, 'hoot:status', '2', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (189, 'name', 'Starbucks');
INSERT INTO node_tags (node_id, k, v, version) VALUES (189, 'name', 'Starbucks', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (189, 'amenity', 'cafe');
INSERT INTO node_tags (node_id, k, v, version) VALUES (189, 'amenity', 'cafe', 1);
/* create node 191*/
INSERT INTO nodes (node_id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (191, 388753845, -1047191537, 3, true, (now() at time zone 'utc'), 1329041601, 1);
INSERT INTO current_nodes (id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (191, 388753845, -1047191537, 3, true, (now() at time zone 'utc'), 1329041601, 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (191, 'accuracy', '1000');
INSERT INTO node_tags (node_id, k, v, version) VALUES (191, 'accuracy', '1000', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (191, 'note', '2-d');
INSERT INTO node_tags (node_id, k, v, version) VALUES (191, 'note', '2-d', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (191, 'poi', 'yes');
INSERT INTO node_tags (node_id, k, v, version) VALUES (191, 'poi', 'yes', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (191, 'hoot:id', '191');
INSERT INTO node_tags (node_id, k, v, version) VALUES (191, 'hoot:id', '191', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (191, 'hoot:status', '2');
INSERT INTO node_tags (node_id, k, v, version) VALUES (191, 'hoot:status', '2', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (191, 'name', 'Starbucks');
INSERT INTO node_tags (node_id, k, v, version) VALUES (191, 'name', 'Starbucks', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (191, 'amenity', 'cafe');
INSERT INTO node_tags (node_id, k, v, version) VALUES (191, 'amenity', 'cafe', 1);
/* create node 193*/
INSERT INTO nodes (node_id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (193, 388532642, -1048997532, 3, true, (now() at time zone 'utc'), 1329018923, 1);
INSERT INTO current_nodes (id, latitude, longitude, changeset_id, visible, "timestamp", tile, version) VALUES (193, 388532642, -1048997532, 3, true, (now() at time zone 'utc'), 1329018923, 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (193, 'hoot:id', '193');
INSERT INTO node_tags (node_id, k, v, version) VALUES (193, 'hoot:id', '193', 1);
INSERT INTO current_node_tags (node_id, k, v) VALUES (193, 'hoot:status', '1');
INSERT INTO node_tags (node_id, k, v, version) VALUES (193, 'hoot:status', '1', 1);
/* modify way 3*/
INSERT INTO ways (way_id, changeset_id, visible, "timestamp", version) VALUES (3, 3, true, (now() at time zone 'utc'), 2);
UPDATE current_ways SET changeset_id=3, visible=true, "timestamp"=(now() at time zone 'utc'), version=2 WHERE id=3;
DELETE FROM current_way_tags WHERE way_id = 3;
DELETE FROM way_tags WHERE way_id = 3;
INSERT INTO current_way_tags (way_id, k, v) VALUES (3, 'note', '2');
INSERT INTO way_tags (way_id, k, v, version) VALUES (3, 'note', '2', 2);
INSERT INTO current_way_tags (way_id, k, v) VALUES (3, 'hoot:id', '3');
INSERT INTO way_tags (way_id, k, v, version) VALUES (3, 'hoot:id', '3', 2);
INSERT INTO current_way_tags (way_id, k, v) VALUES (3, 'hoot:status', '3');
INSERT INTO way_tags (way_id, k, v, version) VALUES (3, 'hoot:status', '3', 2);
INSERT INTO current_way_tags (way_id, k, v) VALUES (3, 'highway', 'road');
INSERT INTO way_tags (way_id, k, v, version) VALUES (3, 'highway', 'road', 2);
DELETE FROM current_way_nodes WHERE way_id = 3;
DELETE FROM way_nodes WHERE way_id = 3;
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (3, 31, 1, 1);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (3, 31, 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (3, 17, 1, 2);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (3, 17, 2);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (3, 37, 1, 3);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (3, 37, 3);
/* modify way 5*/
INSERT INTO ways (way_id, changeset_id, visible, "timestamp", version) VALUES (5, 3, true, (now() at time zone 'utc'), 2);
UPDATE current_ways SET changeset_id=3, visible=true, "timestamp"=(now() at time zone 'utc'), version=2 WHERE id=5;
DELETE FROM current_way_tags WHERE way_id = 5;
DELETE FROM way_tags WHERE way_id = 5;
INSERT INTO current_way_tags (way_id, k, v) VALUES (5, 'note', '0');
INSERT INTO way_tags (way_id, k, v, version) VALUES (5, 'note', '0', 2);
INSERT INTO current_way_tags (way_id, k, v) VALUES (5, 'hoot:id', '5');
INSERT INTO way_tags (way_id, k, v, version) VALUES (5, 'hoot:id', '5', 2);
INSERT INTO current_way_tags (way_id, k, v) VALUES (5, 'hoot:status', '3');
INSERT INTO way_tags (way_id, k, v, version) VALUES (5, 'hoot:status', '3', 2);
INSERT INTO current_way_tags (way_id, k, v) VALUES (5, 'highway', 'road');
INSERT INTO way_tags (way_id, k, v, version) VALUES (5, 'highway', 'road', 2);
DELETE FROM current_way_nodes WHERE way_id = 5;
DELETE FROM way_nodes WHERE way_id = 5;
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (5, 6, 1, 1);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (5, 6, 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (5, 22, 1, 2);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (5, 22, 2);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (5, 2, 1, 3);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (5, 2, 3);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (5, 18, 1, 4);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (5, 18, 4);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (5, 32, 1, 5);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (5, 32, 5);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (5, 14, 1, 6);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (5, 14, 6);
/* create way 20*/
INSERT INTO ways (way_id, changeset_id, visible, "timestamp", version) VALUES (20, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_ways (id, changeset_id, visible, "timestamp", version) VALUES (20, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (20, 'note', '0');
INSERT INTO way_tags (way_id, k, v, version) VALUES (20, 'note', '0', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (20, 'hoot:id', '20');
INSERT INTO way_tags (way_id, k, v, version) VALUES (20, 'hoot:id', '20', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (20, 'hoot:status', '3');
INSERT INTO way_tags (way_id, k, v, version) VALUES (20, 'hoot:status', '3', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (20, 'highway', 'road');
INSERT INTO way_tags (way_id, k, v, version) VALUES (20, 'highway', 'road', 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 193, 1, 1);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 193, 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 9, 1, 2);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 9, 2);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 30, 1, 3);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 30, 3);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 16, 1, 4);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 16, 4);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 26, 1, 5);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 26, 5);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 12, 1, 6);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 12, 6);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 33, 1, 7);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 33, 7);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 19, 1, 8);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 19, 8);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 3, 1, 9);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 3, 9);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 23, 1, 10);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 23, 10);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 7, 1, 11);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 7, 11);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 28, 1, 12);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 28, 12);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 34, 1, 13);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 34, 13);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 20, 1, 14);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 20, 14);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 4, 1, 15);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 4, 15);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 24, 1, 16);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 24, 16);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 8, 1, 17);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 8, 17);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 29, 1, 18);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 29, 18);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 15, 1, 19);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 15, 19);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (20, 36, 1, 20);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (20, 36, 20);
/* create way 21*/
INSERT INTO ways (way_id, changeset_id, visible, "timestamp", version) VALUES (21, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_ways (id, changeset_id, visible, "timestamp", version) VALUES (21, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (21, 'note', '2');
INSERT INTO way_tags (way_id, k, v, version) VALUES (21, 'note', '2', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (21, 'hoot:id', '21');
INSERT INTO way_tags (way_id, k, v, version) VALUES (21, 'hoot:id', '21', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (21, 'hoot:status', '3');
INSERT INTO way_tags (way_id, k, v, version) VALUES (21, 'hoot:status', '3', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (21, 'highway', 'road');
INSERT INTO way_tags (way_id, k, v, version) VALUES (21, 'highway', 'road', 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (21, 37, 1, 1);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (21, 37, 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (21, 21, 1, 2);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (21, 21, 2);
/* create way 22*/
INSERT INTO ways (way_id, changeset_id, visible, "timestamp", version) VALUES (22, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_ways (id, changeset_id, visible, "timestamp", version) VALUES (22, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (22, 'note', '0');
INSERT INTO way_tags (way_id, k, v, version) VALUES (22, 'note', '0', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (22, 'hoot:id', '22');
INSERT INTO way_tags (way_id, k, v, version) VALUES (22, 'hoot:id', '22', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (22, 'hoot:status', '3');
INSERT INTO way_tags (way_id, k, v, version) VALUES (22, 'hoot:status', '3', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (22, 'highway', 'road');
INSERT INTO way_tags (way_id, k, v, version) VALUES (22, 'highway', 'road', 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (22, 21, 1, 1);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (22, 21, 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (22, 10, 1, 2);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (22, 10, 2);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (22, 5, 1, 3);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (22, 5, 3);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (22, 25, 1, 4);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (22, 25, 4);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (22, 193, 1, 5);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (22, 193, 5);
/* create way 23*/
INSERT INTO ways (way_id, changeset_id, visible, "timestamp", version) VALUES (23, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_ways (id, changeset_id, visible, "timestamp", version) VALUES (23, 3, true, (now() at time zone 'utc'), 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (23, 'note', '0');
INSERT INTO way_tags (way_id, k, v, version) VALUES (23, 'note', '0', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (23, 'hoot:id', '23');
INSERT INTO way_tags (way_id, k, v, version) VALUES (23, 'hoot:id', '23', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (23, 'hoot:status', '3');
INSERT INTO way_tags (way_id, k, v, version) VALUES (23, 'hoot:status', '3', 1);
INSERT INTO current_way_tags (way_id, k, v) VALUES (23, 'highway', 'road');
INSERT INTO way_tags (way_id, k, v, version) VALUES (23, 'highway', 'road', 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (23, 14, 1, 1);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (23, 14, 1);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (23, 35, 1, 2);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (23, 35, 2);
INSERT INTO way_nodes (way_id, node_id, version, sequence_id) VALUES (23, 21, 1, 3);
INSERT INTO current_way_nodes (way_id, node_id, sequence_id) VALUES (23, 21, 3);
UPDATE changesets SET min_lat=388467218, max_lat=389109693, min_lon=-1048997532, max_lon=-1047145693, num_changes=13 WHERE id=3;
