1)
crear Tablas:

interests:
CREATE TABLE interests (
    id number(5,0),
    interest varchar2 (15)
);

relationships:
CREATE TABLE relationships (
    matchinging_user_id NUMBER(5, 0),
    matcher_user_id     NUMBER(5, 0),
    realtionship_status        NUMBER(5, 0),
    blocked number(1,0),
    crated_at date
    
);

users:
CREATE TABLE users (
    id         NUMBER(5, 0),
    username   NUMBER(5, 0),
    birth_day  DATE,
    pic        VARCHAR2(20),
    about_me   VARCHAR2(150),
    created_at DATE
);
	
users_interests:
CREATE TABLE users_interests (
    id_interest NUMBER(5, 0),
    id_user     NUMBER(5, 0),
    rate        NUMBER(5, 0)
);
relationship_statuses:
CREATE TABLE relationship_statuses (
    id_interest NUMBER(5, 0),
    status varchar2(15)
);



1.2.1 PRIMARY KEY


interests

ALTER TABLE interests
ADD CONSTRAINT pk_interests
PRIMARY KEY(id);

users_interests

ALTER TABLE users_interests
ADD CONSTRAINT pk_users_interests
PRIMARY KEY(id_interest,id_user);

users

ALTER TABLE users
ADD CONSTRAINT pk_users
PRIMARY KEY(id);

relationships

ALTER TABLE relationships
ADD CONSTRAINT pk_relationships
PRIMARY KEY(matchinging_user_id,matched_user_id);

relationships_statuses

ALTER TABLE relationships_statuses
ADD CONSTRAINT pk_relationships_statuses
PRIMARY KEY(id);


1.2.2 UNIQUE KEY

username 

ALTER TABLE users
ADD CONSTRAINT uk_users_username
UNIQUE (username);

interest 

ALTER TABLE interests
ADD CONSTRAINT uk_interests_interest
UNIQUE (status);

status 

ALTER TABLE relationship_statuses
ADD CONSTRAINT uk_relationship_statuses_status
UNIQUE (status);

1.2.3 CHECK

ALTER TABLE users_interests
ADD CONSTRAINT ck_rate
check (rate<=5 and rate >= 0);

1.2.4 FOREIGN KEY

interest-users_interests

ALTER TABLE users_interests
ADD CONSTRAINT fk_id_interest_id
FOREIGN KEY(id_interest)
REFERENCES interests(id);

users-users_interests

ALTER TABLE users_interests
ADD CONSTRAINT fk_id_user_id
FOREIGN KEY(id_users)
REFERENCES users(id);

users-relationships

1)
ALTER TABLE RELATIONSHIPS
ADD CONSTRAINT fk_matching_user_id_id
FOREIGN KEY(matchinging_user_id)
REFERENCES users(id);

2)
ALTER TABLE RELATIONSHIPS
ADD CONSTRAINT fk_matched_user_id_id
FOREIGN KEY(matched_user_id)
REFERENCES users(id);

relationships-relationships_statuses

ALTER TABLE RELATIONSHIPS
ADD CONSTRAINT fk_relationships_status_id
FOREIGN KEY(realtionship_status)
REFERENCES RELATIONSHIP_STATUSES(id);


1.2.5 NOT NULL

interest

ALTER TABLE interests MODIFY
    interest not_null_intersts
        NOT NULL enable;


rate

ALTER TABLE users_interests MODIFY
    rate not_null_rate
        NOT NULL enable;

status

ALTER TABLE relationship_statuses MODIFY
    status not_null_status
        NOT NULL enable;

username

ALTER TABLE users MODIFY
    username not_null_username
        NOT NULL enable;

relationship_status

ALTER TABLE relationships MODIFY
    relationship_status not_null_relationship_satatus
        NOT NULL ENABLE;

blocked

ALTER TABLE relationships MODIFY
    blocked not_null_blocked
        NOT NULL ENABLE;




















2) id_user


interests

CREATE SEQUENCE seq_interests
increment by 1
start with 1;

alter table interests
modify id integer default seq_interests.NEXTVAL;


relationship_statuses

CREATE SEQUENCE seq_relationship_statuses
increment by 1
start with 1;

alter table relationship_statuses
modify id integer default seq_relationship_statuses.NEXTVAL;


users

CREATE SEQUENCE seq_users
increment by 1
start with 1;

alter table users
modify id integer default seq_users.NEXTVAL;




