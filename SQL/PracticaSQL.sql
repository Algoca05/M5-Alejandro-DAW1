DROP TABLE users_interests;

DROP TABLE relationships;

DROP TABLE relationship_statuses;

DROP TABLE users;

DROP TABLE interests;

DROP SEQUENCE seq_interests;

DROP SEQUENCE seq_relationship_statuses;

DROP SEQUENCE seq_users;
 



--1)
--crear Tablas:

--interests:
CREATE TABLE interests (
    id number(5,0),
    interest varchar2 (15)
);

--relationships:
CREATE TABLE relationships (
    matchinging_user_id NUMBER(5, 0),
    matched_user_id     NUMBER(5, 0),
    relationship_status        NUMBER(5, 0),
    blocked number(1,0),
    created_at date
    
);

--users:
CREATE TABLE users (
    id         NUMBER(5, 0),
    username   VARCHAR2(15),
    birth_day  DATE,
    pic        VARCHAR2(20),
    about_me   VARCHAR2(150),
    created_at DATE
);
	
--users_interests:
CREATE TABLE users_interests (
    id_interest NUMBER(5, 0),
    id_user     NUMBER(5, 0),
    rate        NUMBER(5, 0)
);
--relationship_statuses:
CREATE TABLE relationship_statuses (
    id NUMBER(5, 0),
    status varchar2(15)
);



--1.2.1 PRIMARY KEY


--interests

ALTER TABLE interests
ADD CONSTRAINT pk_interests
PRIMARY KEY(id);

--users_interests

ALTER TABLE users_interests
ADD CONSTRAINT pk_users_interests
PRIMARY KEY(id_interest,id_user);

--users

ALTER TABLE users
ADD CONSTRAINT pk_users
PRIMARY KEY(id);

--relationships

ALTER TABLE relationships
ADD CONSTRAINT pk_relationships
PRIMARY KEY(matchinging_user_id,matched_user_id);

--relationship_statuses

ALTER TABLE relationship_statuses
ADD CONSTRAINT pk_relationship_statuses
PRIMARY KEY(id);


--1.2.2 UNIQUE KEY

--username 

ALTER TABLE users
ADD CONSTRAINT uk_users_username
UNIQUE (username);

--interest 

ALTER TABLE interests
ADD CONSTRAINT uk_interests_interest
UNIQUE (interest);

--status 

ALTER TABLE relationship_statuses
ADD CONSTRAINT uk_relationship_statuses_status
UNIQUE (status);

--1.2.3 CHECK

ALTER TABLE users_interests
ADD CONSTRAINT ck_rate
check (rate<=5 and rate >= 0);

--1.2.4 FOREIGN KEY

--interest-users_interests

ALTER TABLE users_interests
ADD CONSTRAINT fk_id_interest_id
FOREIGN KEY(id_interest)
REFERENCES interests(id);

--users-users_interests

ALTER TABLE users_interests
ADD CONSTRAINT fk_id_user_id
FOREIGN KEY(id_user)
REFERENCES users(id);

--users-relationships

--1)
ALTER TABLE RELATIONSHIPS
ADD CONSTRAINT fk_matching_user_id_id
FOREIGN KEY(matchinging_user_id)
REFERENCES users(id);

--2)
ALTER TABLE RELATIONSHIPS
ADD CONSTRAINT fk_matched_user_id_id
FOREIGN KEY(matched_user_id)
REFERENCES users(id);

--relationships-relationship_statuses

ALTER TABLE RELATIONSHIPS
ADD CONSTRAINT fk_relationships_status_id
FOREIGN KEY(relationship_status)
REFERENCES RELATIONSHIP_STATUSES(id);


--1.2.5 NOT NULL

--interest

ALTER TABLE interests MODIFY
    interest 
        NOT NULL enable;


--rate

ALTER TABLE users_interests MODIFY
    rate 
        NOT NULL enable;

--status

ALTER TABLE relationship_statuses MODIFY
    status 
        NOT NULL enable;

--username

ALTER TABLE users MODIFY
    username 
        NOT NULL enable;

--relationship_status

ALTER TABLE relationships MODIFY
    relationship_status 
        NOT NULL ENABLE;

--blocked

ALTER TABLE relationships MODIFY
    blocked 
        NOT NULL ENABLE;




















--2) 

--2.1

--interests

CREATE SEQUENCE seq_interests
increment by 1
start with 1;

alter table interests
modify id integer default seq_interests.NEXTVAL;


--relationship_statuses

CREATE SEQUENCE seq_relationship_statuses
increment by 1
start with 1;

alter table relationship_statuses
modify id integer default seq_relationship_statuses.NEXTVAL;


--users

CREATE SEQUENCE seq_users
increment by 1
start with 1;

alter table users
modify id integer default seq_users.NEXTVAL;



--2.2

INSERT INTO relationship_statuses ( status ) VALUES ( 'Friend Zone' );

INSERT INTO relationship_statuses ( status ) VALUES ( 'Couple' );

INSERT INTO relationship_statuses ( status ) VALUES ( 'Lovers' );

INSERT INTO relationship_statuses ( status ) VALUES ( 'Broken Up' );

INSERT INTO relationship_statuses ( status ) VALUES ( 'Not Interested' );

---2.3

INSERT INTO interests ( interest ) VALUES ( 'Movies' );

INSERT INTO interests ( interest ) VALUES ( 'Cooking' );

INSERT INTO interests ( interest ) VALUES ( 'Dancing' );

INSERT INTO interests ( interest ) VALUES ( 'Volunteering' );

INSERT INTO interests ( interest ) VALUES ( 'Yoga' );

INSERT INTO interests ( interest ) VALUES ( 'Exercise' );

INSERT INTO interests ( interest ) VALUES ( 'Traveling' );

--2.4

INSERT INTO users (username,birth_day,pic,about_me)
VALUES ('Carol',TO_DATE('17/08/2000'),'Has no pic','Initially, I am seeking friendship with people who share my interests, although I do not rule out falling in love.');
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 1,1,3 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 1,7,4 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 1,4,5 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 1,6,3 );

INSERT INTO users (username,birth_day,pic,about_me)
VALUES ('Nestor',TO_DATE('30/01/1994'),'nestor_pic_001.png','I am looking for my soulmate to travel the world with.');
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 2,5,5 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 2,7,5 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 2,3,2 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 2,4,5 );

INSERT INTO users (username,birth_day,pic,about_me)
VALUES ('Nadia',TO_DATE('22/02/1999'),'nadia_004.png','Professional dancer. I love exercising, and I''ve started learning to cook... and I love it!');
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 3,3,5 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 3,7,2 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 3,2,4 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 3,6,5 );

INSERT INTO users (username,birth_day,pic,about_me)
VALUES ('Jose',TO_DATE('02/12/2002'),'jose_013.png','Thirsty for love. ;)');
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 4,1,4 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 4,7,4 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 4,4,2 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 4,6,3 );
    INSERT INTO users_interests ( id_user,id_interest,rate ) VALUES ( 4,2,1 );


--2.5
--cooking de 1 a 5 en jose
update users_interests
set rate = 5
where id_user = 4 and id_interest = 2;

--2.6
--1)
INSERT INTO relationships (
    matchinging_user_id,
    matched_user_id,
    relationship_status,
    blocked,
    created_at
) VALUES (
    3,
    4,
    1,
    0,
    sysdate
);
--2)

UPDATE relationships set 

    relationship_status = 5
WHERE
        matchinging_user_id = 3
    AND matched_user_id = 4;

UPDATE relationships set 

    blocked = 1
WHERE
        matchinging_user_id = 3
    AND matched_user_id = 4;

--2.7
--1)
INSERT INTO relationships (
    matchinging_user_id,
    matched_user_id,
    relationship_status,
    blocked,
    created_at
) VALUES (
    1,
    2,
    2,
    0,
    sysdate
);

--2)
INSERT INTO relationships (
    matchinging_user_id,
    matched_user_id,
    relationship_status,
    blocked,
    created_at
) VALUES (
    2,
    1,
    2,
    0,
    sysdate
);









--2.8

CREATE TABLE new_users_interests
    AS
        SELECT
            *
        FROM
            users_interests;

--2.9

update new_users_interests
set rate = 3;

--2.10

DELETE FROM new_users_interests
WHERE
    rate = 1;

--2.11

TRUNCATE TABLE new_users_interests;

--2.12

DROP TABLE new_users_interests;

--2.13

CREATE VIEW v_unblocked_relationships AS
    SELECT
        matchinging_user_id,
        matched_user_id,
        relationship_status,
        blocked
    FROM
        relationships
    WHERE
        blocked = 0;